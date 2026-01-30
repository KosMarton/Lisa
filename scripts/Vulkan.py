import os
import subprocess
import sys
from pathlib import Path

import Utils

from io import BytesIO
from urllib.request import urlopen
from zipfile import ZipFile

VULKAN_SDK = os.environ.get('VULKAN_SDK')

# Frissitve a te verziodra (1.4.335.0) es dinamikus linkekre
LISA_VULKAN_VERSION = '1.4.335.0'

# A linkeket 'f-string'-re csereltem, igy automatikusan a fenti verziot hasznaljak
# Es a szervert atirtam sdk.lunarg.com-ra, ami stabilabb
VULKAN_SDK_INSTALLER_URL = f'https://sdk.lunarg.com/sdk/download/{LISA_VULKAN_VERSION}/windows/vulkan_sdk.exe'
VULKAN_SDK_EXE_PATH = 'Lisa/vendor/VulkanSDK/VulkanSDK.exe'

# Itt javitottuk a linket a regi files.lunarg.com-rol:
VulkanSDKDebugLibsURL = f'https://sdk.lunarg.com/sdk/download/{LISA_VULKAN_VERSION}/windows/VulkanSDK-{LISA_VULKAN_VERSION}-DebugLibs.zip'

OutputDirectory = "Lisa/vendor/VulkanSDK"
TempZipFile = f"{OutputDirectory}/VulkanSDK.zip"

def InstallVulkanSDK():
    # --- Create directory if it does not exist ---
    Path(VULKAN_SDK_EXE_PATH).parent.mkdir(parents=True, exist_ok=True)
    # ---------------------------------------------

    print('Downloading {} to {}'.format(VULKAN_SDK_INSTALLER_URL, VULKAN_SDK_EXE_PATH))
    Utils.DownloadFile(VULKAN_SDK_INSTALLER_URL, VULKAN_SDK_EXE_PATH)
    print("Done!")
    print("Running Vulkan SDK installer...")
    os.startfile(os.path.abspath(VULKAN_SDK_EXE_PATH))
    print("Re-run this script after installation")

def InstallVulkanPrompt():
    print("Would you like to install the Vulkan SDK?")
    install = Utils.YesOrNo()
    if (install):
        InstallVulkanSDK()
        quit()

def CheckVulkanSDK():
    if (VULKAN_SDK is None):
        print("You don't have the Vulkan SDK installed!")
        InstallVulkanPrompt()
        return False
    elif (LISA_VULKAN_VERSION not in VULKAN_SDK):
        print(f"Located Vulkan SDK at {VULKAN_SDK}")
        print(f"You don't have the correct Vulkan SDK version! (Lisa requires {LISA_VULKAN_VERSION})")
        InstallVulkanPrompt()
        return False
    
    print(f"Correct Vulkan SDK located at {VULKAN_SDK}")
    return True

def CheckVulkanSDKDebugLibs():
    shadercdLib = Path(f"{OutputDirectory}/Lib/shaderc_sharedd.lib")
    if (not shadercdLib.exists()):
        print(f"No Vulkan SDK debug libs found. (Checked {shadercdLib})")
        print("Downloading", VulkanSDKDebugLibsURL)
        
        # Create directory here as well just in case
        Path(OutputDirectory).mkdir(parents=True, exist_ok=True)
        
        try:
            with urlopen(VulkanSDKDebugLibsURL) as zipresp:
                with ZipFile(BytesIO(zipresp.read())) as zfile:
                    zfile.extractall(OutputDirectory)
        except Exception as e:
            print(f"Hiba a letoltes kozben: {e}")
            print("Ellenorizd az internetkapcsolatot vagy a VPN/Tuzfal beallitasokat.")
            return False

    print(f"Vulkan SDK debug libs located at {OutputDirectory}")
    return True
# Intel® Neural Compute Stick 2 (NCS2) Setup Guide for Use with Intel® Distribution of OpenVINO™ toolkit {#openvino_docs_install_guides_ncs2_setup_guide}

@sphinxdirective

.. _ncs guide:

@endsphinxdirective

## Linux

Once you have your OpenVINO installed, follow the steps to be able to work on NCS2:

1. Go to the install_dependencies directory:
   ```sh
   cd <INSTALL_DIR>/intel/openvino_2022/install_dependencies/
   ```
2. Run the `install_NCS_udev_rules.sh` script:
   ```
   ./install_NCS_udev_rules.sh
   ```
3. You may need to reboot your machine for this to take effect.

You've completed all required configuration steps to perform inference on Intel® Neural Compute Stick 2. 
Proceed to the <a href="#get-started">Start Using the Toolkit</a> section to learn the basic OpenVINO™ toolkit workflow and run code samples and demo applications.

@sphinxdirective

.. _ncs guide macos:

@endsphinxdirective

## macOS

These steps are required only if you want to perform inference on Intel® Neural Compute Stick 2
powered by the Intel® Movidius™ Myriad™ X VPU. For more details, see also the
[Get Started page for Intel® Neural Compute Stick 2](https://software.intel.com/en-us/neural-compute-stick/get-started).

To perform inference on Intel® Neural Compute Stick 2, the `libusb` library is required. You can build it from the [source code](https://github.com/libusb/libusb) or install using the macOS package manager you prefer: [Homebrew*](https://brew.sh/), [MacPorts*](https://www.macports.org/) or other.

For example, to install the `libusb` library using Homebrew\*, use the following command:
```sh
brew install libusb
```

You've completed all required configuration steps to perform inference on your Intel® Neural Compute Stick 2.
Proceed to the <a href="#get-started">Start Using the Toolkit</a> section to learn the basic OpenVINO™ toolkit workflow and run code samples and demo applications.

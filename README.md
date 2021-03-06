# sysupdate

A program which attempts to connect to known package managers and update all
system software on a GNU/Linux system.

## Table of Contents

- [Introduction](#introduction)
- [Supported Command-Line Arguments](#supported-command-line-arguments)
- [Currently Supported Software](#currently-supported-software)
  - [Native Package Managers](#native-package-managers)
    - [Regarding PackageKit](#regarding-packagekit)
  - [Universal Package Managers](#universal-package-managers)
  - [Software Distributions](#software-distributions)
  - [Additional Software](#additional-software)
- [Compilation Instructions](#compilation-instructions)
- [References](#references)

## Introduction

This program has been built with a single function in mind: to provide a
junction to all known package managers included within a typical desktop Linux
distribution, and perform all software upgrade tasks at-once. Each package
manager or piece of software (listed below) will only attempt an update if they
are installed. For example, this program will not attempt to update an Ubuntu
system using Fedora's update manager.

Native package managers are tested for initially, and in the absence of these
the program will stop. This is to ensure that this program is only operating in
a familiar environment and will not attempt to update an operating system which
is unknown. New Linux distributions and package management software will be
added on an ad-hoc basic as and when they can be thoroughly tested.

## Supported Command-Line Arguments

`sysupdate` can make use of the following command-line arguments to display
information regarding version, license, and help.

```bash
sysupdate -h         # Display help and exit.
sysupdate -v         # Display version/license information.
sysupdate --help     # Display help and exit.
sysupdate --version  # Display version/license information.
```

## Currently Supported Software

At present, these are the known package managers supported by this program:

### Native Package Managers

These package managers typically form the foundation of a standard Linux
distribution and as such, they are to be considered essential. This program will
attempt to detect these and exit if none are detected.

- **APT** (Debian / Ubuntu / Mint or compatible)
- **DNF** (CentOS 8+ / Fedora / RHEL 8+ or compatible)
- **EOPKG** (Solus or compatible)
- **PackageKit** (KDE Neon or compatible)
- **Pacman** (Arch or compatible)
- **RPM-OSTree** (Fedora Silverblue or compatible)
- **XBPS** (Void or compatible)
- **Zypper** (SLE / openSUSE or compatible)

#### Regarding PackageKit

Note that `PackageKit` may also be present on these systems as a secondary
package manager and performs the same tasks as their counterpart of `APT` or
`DNF` (for example). With this in mind, `sysupdate` will attempt to update using
`PackageKit` instead to ensure system stability - Operating Systems such as
[KDE Neon](https://neon.kde.org/) will not fetch *all* system updates using
`APT` alone and this will eventually break the system and neglect important
security updates.

### Universal Package Managers

These package managers are non-essential and may be detected on almost any
standard Linux distribution. If these are not detected, the program will
continue, ignoring these technologies.

- **Flatpak** (Universal)
- **Snap** (Universal)

### Software Distributions

These packages contain additional software which form (for example) additional
programming languages and version managers.

- **Anaconda/Miniconda 3** (Python, user-installed at `~/anaconda3` or
  `~/miniconda3`).

- **rustup** (Rust, user installed at `~/.cargo/bin/rustup`).

### Additional Software

Software which may be updated but is not considered a package manager will be
listed within this section.

- **ClamAV**

## Compilation Instructions

These commands should succeed and allow the program to run under any GNU/Linux
distribution which has a working `gcc` installation. This program was written in
a Fedora Silverblue 32 (x86_64) environment with no additional dependencies.

Note that source code is contained within the `src` directory and so these
commands must be run from that location within your Terminal (as current user).

```bash
# Build the executable.
gcc -std=c11 main.c check_network.c update_software.c -o sysupdate

# Launch the program.
./sysupdate
```

## References

- **Linux kernel coding style**
  - <https://www.kernel.org/doc/html/v4.10/process/coding-style.html>

- **Re: clean up kernel_{read,write} & friends v2**
  - <https://lkml.org/lkml/2020/5/29/1038>

- **`check_network.h`** / **`check_network.c`**
  - <https://bbs.archlinux.org/viewtopic.php?id=213878>

- **Evaluate PackageKit before other Package Managers**
  - <https://neon.kde.org/faq#command-to-update>

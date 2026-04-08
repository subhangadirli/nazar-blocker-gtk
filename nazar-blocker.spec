%define version 1.0
%define release 1

Name:           nazar-blocker
Version:        %{version}
Release:        %{release}%{?dist}
Summary:        System tray application for protection from the evil eye

License:        MIT
URL:            https://github.com/SubhanGadirli/nazar-blocker-gtk
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  meson
BuildRequires:  ninja-build
BuildRequires:  gcc
BuildRequires:  gettext
BuildRequires:  gtk3-devel
BuildRequires:  libayatana-appindicator-devel

Requires:       gtk3
Requires:       libayatana-appindicator

%description
A minimal system tray application (nazar blocker) that displays a protective
evil eye icon. Features AppIndicator integration for modern Linux desktops
and multi-language support.

%prep
%autosetup

%build
%meson
%meson_build

%install
%meson_install

%files
%license LICENSE.md
%doc Readme.md
%{_bindir}/nazar
%{_datadir}/applications/nazar.desktop
%{_datadir}/icons/hicolor/scalable/apps/nazar.svg
%{_datadir}/locale/tr/LC_MESSAGES/nazar.mo

%changelog
* Wed Apr 08 2026 Subhan Gadirli <subhanqedirli@protonmail.com> - 1.0-1
- Stable 1.0 release
- GTK 3 implementation with AppIndicator support
- Turkish translation included
- RPM packaging for Fedora and openSUSE
- Flatpak support for universal Linux distribution

# Maintainer: Subhan Gadirli <subhanqedirli@protonmail.com>
pkgname=nazar-blocker
pkgver=1.0
pkgrel=1
pkgdesc="System tray application for protection from the evil eye"
arch=('x86_64' 'aarch64')
url="https://github.com/SubhanGadirli/nazar-blocker-gtk"
license=('MIT')
depends=('gtk3' 'libayatana-appindicator')
makedepends=('meson' 'ninja' 'gettext')
source=("$pkgname-$pkgver.tar.gz::https://github.com/SubhanGadirli/nazar-blocker-gtk/archive/v$pkgver.tar.gz")
sha256sums=('SKIP')

build() {
  cd "$pkgname-gtk-$pkgver"
  meson setup builddir --prefix=/usr
  meson compile -C builddir
}

package() {
  cd "$pkgname-gtk-$pkgver"
  DESTDIR="$pkgdir" meson install -C builddir
}

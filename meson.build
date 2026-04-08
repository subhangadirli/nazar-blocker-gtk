project('nazar', 'c',
  version: '1.0',
  default_options: [
    'warning_level=3',
    'werror=true',
    'c_std=c11',
  ],
)

gtk_dep = dependency('gtk+-3.0')

appindicator_dep = dependency('ayatana-appindicator3-0.1', required: false)
if not appindicator_dep.found()
  appindicator_dep = dependency('appindicator3-0.1', required: false)
endif

i18n = import('i18n')

subdir('po')

prefix = get_option('prefix')
localedir = prefix / get_option('localedir')

add_project_arguments([
  '-DPACKAGE="' + meson.project_name() + '"',
  '-DLOCALEDIR="' + localedir + '"',
], language: 'c')

deps = [gtk_dep]
if appindicator_dep.found()
  deps += appindicator_dep
  add_project_arguments('-DHAVE_APPINDICATOR', language: 'c')
else
  warning('libayatana-appindicator not found, building without system tray support')
endif

executable('nazar',
  'src/main.c',
  dependencies: deps,
  install: true,
)

install_data('src/nazar.svg',
  install_dir: get_option('datadir') / 'icons' / 'hicolor' / 'scalable' / 'apps',
)

install_data('nazar.desktop',
  install_dir: get_option('datadir') / 'applications',
)

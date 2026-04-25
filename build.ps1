if (Test-Path ./build) {
  Set-Location build
  meson compile
}
else {
  meson setup build
  Set-Location build
  ninja
}
& ./game

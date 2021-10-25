# Menjalankan ADT di Windows
# Pastikan sudah menginstall gcc dan make di windows

$ADT_NAME=$args[0]

if ($ADT_NAME) {
  $LOCATION = Get-ChildItem -Path "./src" -Recurse main_$ADT_NAME.c

  if($LOCATION.Length -gt 0){
    $FILE_LOCATION = $LOCATION[0].FullName
    
    make clean
    make "main_builder/$FILE_LOCATION"
    
    $RESULT = Get-ChildItem -Path "./bin" ADT_RUNNER*
    
    if($RESULT.Length -gt 0){
      Clear-Host
      
      $EXT=$RESULT[0].Extension
      $EXEC_PATH = $RESULT[0].FullName

      Move-Item -Path "$EXEC_PATH" -Destination "./bin/$ADT_NAME$EXT"
      & "./bin/$ADT_NAME$EXT"
      Write-Output ""
    }else{
      Write-Warning "Gagal melakukan kompilasi. Membatalkan Aksi."
    }
  }else{
    Write-Error "ADT Tidak ditemukan"
  }
}else{
  Write-Error "Nama ADT Kosong"
  exit
}

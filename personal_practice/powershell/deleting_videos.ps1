$path2 = Read-Host 'Enter path to'
$path1 = Read-Host 'Enter path from'
if (Test-Path -Path $path1) 
{
    if (Test-Path -Path $path2)
    {
        Move-Item -Path $path1 -Destination $path2
    }
    Write-Host 'Done.'
}

else
{
    Write-Host "Path doesn't exist."
}

<#Get-ChildItem -Path E:\PS5\CREATE\Video Clips\Call of Duty®_ Modern Warfare II -Include *.* -File -Recurse | ForEach-Object {$_.Delete()}#>
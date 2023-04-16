$array = Get-Random -count 10 -Maximum 100 -Minimum 1
$biggest = 0
Write-Host $array
foreach ($number in $array)
{
    if ($number -gt $biggest)
    {
        $biggest = $number
    }
}

for ($i = 0; $i -lt $biggest; $i++)
{
    foreach ($number in $array)
    {
        if ($i -eq $number)
        {
            Write-Host $i = $number
        }
        else 
        {
            Write-Host $i
            continue
        }
    }
}
Write-Host $biggest
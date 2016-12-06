open(A,"~/haja.txt") || die;
open(B,"/home/wiss/workspaceMars2/FirstStep/d.dic");
$haja;
while (<A>)
{
  $haja=$_;
  while(<B>)
  {
    if($haja==$_)
    print($_);
  }
  # {print B $_."inst()"}
  # if($_ =~ m/^\"(.*)\".*{print(.*)$/)
}

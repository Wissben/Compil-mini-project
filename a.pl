open(A,"a.l") || die;
open(B,">sortie");
while (<A>)
{
  if($_ =~ m/^\"(.*)\".*{print(.*)$/)
  {print B $_."inst()"}
}

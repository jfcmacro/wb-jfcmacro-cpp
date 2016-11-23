#!/usr/bin/bash

DIRDATA=$HOME/data/courses
stdgroup=st0244-2016-2-$1-stdinfo.dat
evalUnit=evalUnitMidTerm03ST024420162-$2.yaml
groupstdinfo=$DIRDATA/$stdgroup
usercode=$3

echo "evalUnit: $evalUnit"
echo "stdgroup: $stdgroup"
echo "groupstdinfo: $groupstdinfo"

./evalStdRepos --workdir ~/tmp/st0244-2016-2/ --reposdir $1-parcial-03  --evalunitfile $evalUnit --username fcardona --stdlst $usercode --resumen $groupstdinfo

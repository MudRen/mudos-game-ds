// dodge.c

inherit SKILL;
string type() { return "basic"; }

string *dodge_msg = ({
                         "可是偏了幾寸。\n",
                         "但是$n機靈地躲開了。\n",
                         "$n身子一側，閃了開去。\n",
                         "$n立刻反應，及時避開。\n",
                         "但是$n已有準備，不慌不忙的躲開。\n",
                     });



string query_dodge_msg()
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

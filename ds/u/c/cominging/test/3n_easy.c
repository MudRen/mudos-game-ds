#include <ansi.h>
inherit ITEM;

int set_long(string arg);
string note;

void create()
{
        set_name(HIG"3N�P�K����"NOR, ({ "3n scrip", "scrip" }));
        if( clonep() )
        {
                set("unit", "�i");
                set("value", 1);
        }
        setup();
}

string long()
{
        return sprintf("�o�O�@�i 3N �P���K����, ���ۤ@�Ӥj�j�� "HIG"3N"NOR" Mark,\n"
                "�򱵵۫᭱�g�F�@��r�G\n\n%s\n\n\n"HIB"___--- programmed by Cominging ---___"NOR,
                note);
}

int set_long(string arg)
{
        if( !arg ) return 0;
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        if( note = arg )
                return 1;
}

#include <ansi.h>
inherit ITEM;

int set_long(string arg);
string note;

void create()
{
        set_name(HIG"3N牌便條紙"NOR, ({ "3n scrip", "scrip" }));
        if( clonep() )
        {
                set("unit", "張");
                set("value", 1);
        }
        setup();
}

string long()
{
        return sprintf("這是一張 3N 牌的便條紙, 打著一個大大的 "HIG"3N"NOR" Mark,\n"
                "緊接著後面寫了一串字：\n\n%s\n\n\n"HIB"___--- programmed by Cominging ---___"NOR,
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

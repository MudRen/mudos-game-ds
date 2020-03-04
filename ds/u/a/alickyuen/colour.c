#include <ansi.h>
#define CLUB_ID "sky"
#include <armor.h>
inherit ITEM;

void create()
{
        set_name(HIW"�ܦ⾹"NOR, ({ "colour changer","changer" }));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);  
        else
        {
                set("long","�H�H�H�H�H�C\n");
                set("unit","��");
set("value",0);
        }
        setup();
}

void init()
{
        object me=this_player();
        add_action("do_rexx","rex");
          add_action("do_change","change");
	add_action("do_ex", "exc");
}
int do_rexx(string a)
{
        object me=this_player();
        string arg,b;
        if( !a || sscanf(a ,"%s %s",b,arg)!=2 ) return notify_fail("[�榡] rex <����> <���e>\n");
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
        me->set(b,arg + NOR);
        write("�����C\n");
        return 1;
}
int do_change(string arg)
{
          object ob, me;
        mapping me_info,ob_info;
          me= this_player();
        if(!arg) return notify_fail("change <^DH^FW>\n");
                ob = present(arg, environment(me));
                if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));          
                        ob_info["level"]=7;
          return 1;
}
int do_ex(string arg)
{
	string m1, m2;
	object me = this_player();
	if(sscanf(arg, "%s to %s", m1, m2) )
	{
		me->set(m2, me->query(m1) );
	return 1;
	}
	return 1;
}

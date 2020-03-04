#include <ansi.h>
inherit ITEM;
void create()
{


       set_name(HIY"神 "HIW"器"NOR, ({"god machine", "machine"}));
        set_weight(1000);
        set("unit", "顆");
        set("long", @LONGpromote用
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_pro","pr");
 
}

int do_pro(string arg)
{
    object ob, me; 
    me= this_player();    string old_status, new_status, my_id;
    int my_level, ob_level, level;

    if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
        return notify_fail("指令格式﹕promote <使用者> <等級>\n");

    if( (level=SECURITY_D->query_valid_level(new_status))==-1 )
        return notify_fail("沒有這種等級。\n");

    ob = find_player(arg);
    if (!ob) {
        if (!ob = FINGER_D->acquire_login_ob(arg))
            return notify_fail ("沒有這個玩家。\n");
    }

    my_level = wiz_level(me);

    old_status = SECURITY_D->get_status(arg);
   ob_level = wiz_level(arg);

    my_id = me->query("id");

    if (my_id == arg)
        return notify_fail("你不可以更改自己的等級。\n");   

    if( (my_level <= ob_level && wizhood(me) != "(manager)" ) )
        return notify_fail("你不能更動他的職位。\n");
    if( ( new_status == "(arch)" && wizhood(me) == "(arch)" ) )
        return notify_fail("大巫師只能提昇別人等級至(Wizard)。\n");
    seteuid(getuid());

    if( !(SECURITY_D->set_status(me, arg, new_status)) )
        return notify_fail("修改失敗。\n");

    CHANNEL_D->do_channel( me, "sys",
      sprintf ("將%s(%s)的權限從%s改為%s。\n",
        ob->query("name"), arg, old_status, new_status));
    tell_object (ob, sprintf ("%s(%s)將你的等級變成%s\n",
        me->name(), my_id, new_status));

    ob->save();

      return 1;
}


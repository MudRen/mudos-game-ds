#include <ansi.h>
inherit ITEM;
void create()
{


       set_name(HIY"�� "HIW"��"NOR, ({"god machine", "machine"}));
        set_weight(1000);
        set("unit", "��");
        set("long", @LONGpromote��
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
        return notify_fail("���O�榡�Rpromote <�ϥΪ�> <����>\n");

    if( (level=SECURITY_D->query_valid_level(new_status))==-1 )
        return notify_fail("�S���o�ص��šC\n");

    ob = find_player(arg);
    if (!ob) {
        if (!ob = FINGER_D->acquire_login_ob(arg))
            return notify_fail ("�S���o�Ӫ��a�C\n");
    }

    my_level = wiz_level(me);

    old_status = SECURITY_D->get_status(arg);
   ob_level = wiz_level(arg);

    my_id = me->query("id");

    if (my_id == arg)
        return notify_fail("�A���i�H���ۤv�����šC\n");   

    if( (my_level <= ob_level && wizhood(me) != "(manager)" ) )
        return notify_fail("�A�����ʥL��¾��C\n");
    if( ( new_status == "(arch)" && wizhood(me) == "(arch)" ) )
        return notify_fail("�j�Ův�u�ണ�@�O�H���Ŧ�(Wizard)�C\n");
    seteuid(getuid());

    if( !(SECURITY_D->set_status(me, arg, new_status)) )
        return notify_fail("�ק異�ѡC\n");

    CHANNEL_D->do_channel( me, "sys",
      sprintf ("�N%s(%s)���v���q%s�אּ%s�C\n",
        ob->query("name"), arg, old_status, new_status));
    tell_object (ob, sprintf ("%s(%s)�N�A�������ܦ�%s\n",
        me->name(), my_id, new_status));

    ob->save();

      return 1;
}


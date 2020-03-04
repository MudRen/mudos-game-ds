// Room: /d/gumu/obj/bishou.c�P��
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "�٭��P" , ({ "behead dagger", "dagger" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@����t�W�Q���P���A�n���i�H��(chop)�F��C\n");
                set("value", 0);
                set("material", "iron");
        }
        setup();
}

void init()
{
      add_action("mark_success", "chop");
}

int mark_success(string arg)
{
        object target, ob,name1, me = this_player();

        name1 = me->query("id"); 
    if(!arg) return notify_fail("�A�n�٤���H\n");  
        target = present(arg, environment(me));  
        if(!target)
                return notify_fail("�䤣��o�ӪF��C\n");
        if(!target->is_corpse())
                return notify_fail("�ݲM���I�A�����O����C\n");
        if(target->query("no_head"))
                return notify_fail("�������w�g�S�����ŤF�C\n");
        if(!target->is_character())
                return notify_fail("�������w�g�G��F�C\n");
        message_vision(HIR"$N���_�P�� �A���$n����l�B�r�a�٤F�U�h�I\n"NOR, me, target);
        ob=new(__DIR__"head");
        ob->set_name(target->query("victim_name")+"������",({"head"}));
        ob->set("long", "�o�O�@��"+target->query("victim_name")+"�����šC\n");    
        if(target->query("victim_user")) 
        ob->set("victim_user", 1);  
        if(target->query("kill_by")) 
        ob->set("kill_by", target->query("kill_by"));
        target->delete("kill_by");
        message_vision(HIR"$N�N$n�٤F�U�ӡA���b�⤤�C\n"NOR, me, ob);
        ob->move(me);
        target->set("name", "�L�Y����");
        target->set("no_head", 1);
        target->set("long", "�@��L�Y����A�G��|���A�����i�ơC\n");           
        return 1;
}


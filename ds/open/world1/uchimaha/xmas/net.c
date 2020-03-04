#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"�˺�"NOR, ({ "bamboo net","net" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�K����(catch)�ʪ��Ϊ��˺��C\n");
                set("unit", "�K");
                set("value",5);
                set("material","wood");
        }
        setup();
}

void init()
{ 
        add_action("do_catch","catch");
}

int do_catch(string arg)
{
        object me,obj;
        me=this_player();
        if( !arg ) return notify_fail("�A�Q�����֡H\n");
   if(me->is_busy() ) return notify_fail("�A�����ۡC\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("�o�̨S���o�تF��C\n");
        if( !obj->is_character() || obj->is_corpse() ) return notify_fail("�A�u�ஷ�������ͪ��C\n");
         if(userp(obj)) return notify_fail("�A������������a�@�C\n");

        message_vision("$N�۰_�⤤���˺��A�@�⩹$n�n�h�C\n",me,obj);

        if(!obj->query("Merry_Xmas"))
        {
                message_vision(YEL"$n�����Q�F"+me->query("name")+"("+me->query("id")+")�X�Ӥj�ե�.\n"NOR,me,obj);
        }
        else {
        if( random(100) > 70 )
        {

message_vision(HIW "�����H�J�Ʀ��@�D�������ĤW�ѡI�I\n"NOR,me);
                me->add("Merry_Xmas/chicken",1);
        tell_object(me,HIC"�]���A��~������F�@���ʪ��Aı���߱��۷�r�֡C\n"NOR);
        me->receive_heal("hp",10);
me->receive_heal("mp",10);
        me->receive_heal("ap",10);
        set("long", "�o�O�@�K����(catch)�ʪ��Ϊ��˺��A�b�˺����`�W�O���ۡG\n"
        +me->query("name")+"�ثe�@�����F"+me->query("Merry_Xmas/chicken")+"���ʪ��C",
        );

                destruct(obj);
        }
        else
        {
        message_vision(HIW "������ı$N���|�ʡA�ͻH�@���A���L�F�˺��C\n"NOR,me);
        me->start_busy(1);
        }
        }
        return 1;

}


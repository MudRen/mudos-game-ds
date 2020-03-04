#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIW"�F�_"NOR"�A�L");
set("long", @LONG 
�A�ש󨫥X�F�h�A��, �A�Pı��U�������B, �o�̦��ǰ��j
�����M�ᦷ, �A�ݨ��W���@�Ӧp�Y�`��j�����_, �����٦�
�Ǫ��Y���b�r��.
LONG
        );
        set("exits",(["south":__DIR__"en38",
                      "northwest":__DIR__"en40",
               ]));
        
        set("item_desc",([
        "���_":"�o�O�@�Ӧ��Y�`��j�����_�A��L�K�U���G�i�H��줣���������E\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="south" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
void init()
{ 
         add_action("do_pick","pick");
}
int do_pick(string arg)
{
          object me;
          me=this_player(); 

        if (!arg || arg =="")
        return notify_fail("�A�n�K�U����H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
          if(arg != "���_")
            return 0;
          else {
            message_vision("$N�g���@�_�A�k�Q����_�K�U..\n\n",me);
            message_vision("��$N�ʤ�K�U���_�ɡA��M���_���F�U�ӡA�e�������������q���_�̴�X�C\n",me);
            message_vision("�@�j�s�e����$N�����W���W�A�h��$N�z�z�j�s�A�y�ɹM����ˡC\n",me); 
            me->start_busy(3+random(3));            switch(random(100)){
            case 1..20:
            me->receive_wound("head",2+random(5));
            me->receive_wound("body",2+random(5));
            me->apply_condition("blooding", me->query_condition("blooding")+(random(3)+2));
            break;
            case 21..40:
            me->receive_wound("left_leg",2+random(5));
            me->receive_wound("right_leg",2+random(5)); 
            me->apply_condition("blooding", me->query_condition("blooding")+(random(3)+2));
            break;            case 41..60:
            me->receive_wound("left_arm",2+random(5));
            me->receive_wound("right_arm",2+random(5)); 
            me->apply_condition("blooding", me->query_condition("blooding")+(random(3)+2));
            break;
            case 61..80: 
            message_vision("\n$N"HIW"�Q�e�����A�y�⤣�ӥ��`�A�ݨӬO"MAG"���r"HIW"�F�E\n"NOR,me);
            me->apply_condition("poison", me->query_condition("poison")+random(10));
            break;
            default:
            message_vision("\n$N"HIW"�Q�e�����A�y�⤣�ӥ��`�A�ݨӬO"MAG"���r"HIW"�F�E\n"NOR,me);
            me->apply_condition("poison", me->query_condition("poison")+random(20));
            break;
            }
            return 1;
          }
}



#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�c��");
        set("long", @LONG
�@���g�ǡA�Ǽs�K�ءA�`�i�|�M�A�W�Y�u���@���u�����p���A�a�W��
�O�ûG����d�A�Ǩ���n�ۤ@�]�]���G��̴ߡA�٥i�ݨ�ư��w�o�䪺��
���B���͡A�㶡�c�ǡA�����۴X��ǤH�A��O�������ʡC
LONG
        );
        set("light",1);
        set("world", "past");
   set("objects",([
    __DIR__"npc/man2":2,
       ]) );
        set("no_clean_up", 0);
        setup();
}

int room_effect(object me)
{
        switch(random(15))
        {
         case 0:
         write("�~�Y�~�a�U�F�}�}�j�B�A�Ǥ��n�ɲT�_���ӤF...\n");
         tell_object(me, HIC "�Aı�o�㰦�}���b���̡A�ᬰ�����C\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write("�a�W���ꤣ�����d�g�o�X�}�}���D..... \n");
         tell_object(me, HIY "�A�D�۳o�Ѩ��D�A�uı�o�����@�}���V...\n" NOR ); 
         me->receive_damage("hp",20);
         me->receive_damage("mp",30);
         return 1;

         case 2:
         write("�|�P�Ů�]���y�q�S�A�׾����_�ӤF.....\n");
         tell_object(me, HIB "�A�uı�o�ݤ��дe����....\n" NOR ); 
         me->receive_damage("ap",40);
         return 1;

         case 3:
         write("�ǥ~���G���H�b���N�A�㶡�Ǥ��n���������.... \n");
         tell_object(me, HIR "�A�uı�o�ּ����Y�F....\n" NOR ); 
         me->receive_damage("mp",40);
         return 1;

         case 4:
         write("�Ǩ��G�ꪺ�̴ߵo�X�}�}���c��.... \n");
         tell_object(me, HIY "�A���T�æR�_��....\n" NOR ); 
         me->receive_damage("hp",30);
         return 1;

         case 5:
         write("�A�ݵۥ|�P���H�b�O�{�릾���A�j�a�������h...\n");
         tell_object(me, HIC "�Aı�o�ۤw������G�]�V�ӶV�c��F...\n" NOR ); 
         me->receive_damage("mp",30);   
         me->receive_damage("ap",30);
         return 1;

         case 6:
         write("�Ǩ����G���B�G�͵o�X�}�}�O�H���D���ͯ��...\n");
         tell_object(me, HIB "�A�D�۳o�Ѩ��D�A�uı�o�|�ϵo�n�A���H�Ԩ�...\n" NOR ); 
         me->receive_damage("hp",20);   
         me->receive_damage("ap",20);
         return 1;

     case 7:
         case 8:
   case 9:
         write(HIW "�A�Q�_�Ѹt���廡�L���ܡA�n�ɤߤ��E�_�@�ѥ���I�I\n" NOR);
         me->receive_heal("mp",50);
         me->receive_heal("ap",50);
         me->receive_heal("hp",100);
         return 1;

         default:       return 1;
        }
}



void init()
{
          add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if(!arg|| arg!="�}�}") return 0;
        if(me->is_busy()) return notify_fail("�A���b���C\n");
        message_vision("$N�@�Y���A�q���p�i�Ӫ��}�}���F�X�h�C\n",me);
        me->move(__DIR__"vroad4");
        tell_room(environment(me),me->query("name")+"���M�X�{�b�A�����e�C\n",({ me }) );
        return 1;
}




#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"�C���� "HIC"�i���R���}�j"NOR);
        set("long", @LONG
�o�̬ݰ_�Ӽs�j������A�������H�ݰ_�ӡA�|ı�o�j�۵M������ 
�C�A�q�q��ť��@�Ǻq�R�n�A�A���F�@�}�l�A�A�[��F�Ҧ��a��A��
�O�d���X�q���O���Ӫ��q���n���C
LONG);
        set("exits", ([ /* sizeof() == 3 */ 
   "west" : __DIR__"1f_1", 
   "south" : __DIR__"1f_3",    ]));
        
        set("no_recall", 1); 
        set("no_quit",1);       
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/water.c" : 4,
        ]));
        set("world", "past");
        set("no_clean_up", 0);
        set("light",0);

        setup();
}  
 int room_effect(object me)
{
        switch(random(2))
        {


         case 0:
         write(HIC"�}�}����ŧ���A����....\n"NOR);
         tell_object(me, HIC"�A�Pı�����w�F��..�C\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIB"�����ʷ�ŧ���A... \n"NOR);
         tell_object(me, HIB "�A�Q������F��...�C\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;

         default:       
         return 1;
        }
}


#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"�C���� "HIC"�i���R���}�j"NOR);
        set("long", @LONG
�b����A���ǧ����R�p����A�S�����󪺧n���n�A�N�n�����b�j
�۵M�̳o�򪺦w�����R�A���L�j�H�٤����ɭ��B�e�����R�A�A�L�k�w
���U�@��|�o�ͤ���ơA�ҥH���褺�߷Pı�xŸ���w�C
LONG);
        set("exits", ([ /* sizeof() == 3 */ 
   "northeast" : __DIR__"1f_3", 
   "southeast" : __DIR__"1f_5",    ]));
        
        set("no_recall", 1); 
        set("no_quit",1);       
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/water2.c" : 4,
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



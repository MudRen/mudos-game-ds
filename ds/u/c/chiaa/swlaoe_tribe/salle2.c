//u/c/chiaa/swlaoe_tribe/salle2.c

#include <ansi.h>//�w�q��X
inherit ROOM;    //�w�q�ж�
void create()
{
   set("short", WHT"�j�U�᰼"NOR);
   set("long",@LONG
          �o�̬O�j�U�᰼,�o�̥u����ۤ@�i��l�M�@�ǴȤl,
          ���M�A�`�N���l�W���@���u�C�Сv,�l�ާA���`�N�O
          ���A����ı���Q�⥦½�}�ݬ�!!
LONG
);
        set("exits", ([ /* sizeof() == 2 */
      
        "east"    : __DIR__"salle2",       //�j�U2
        "south"   : __DIR__"corridor5",    //���Y5
]));
        set("item_desc",([
        "�C��":"�@���ťժ��C��,½��½�h���S���b�Ӧr�C\n",
]));
            setup();
        set("no_clean_up", 0);
}
void init()
{
        add_action("do_push","push");
}

        int do_push(string str) 
   //�t�η|�N���a�ҿ�J��"push"�o�ӫ��O�᪺�Ҧ�                             
   //��r�H�r�ꫬ�O���޼ƶǵ� do_push()�@ 
   //�N do_push �o�Ө�ƫŧi��                                              
   //int do_push(string str)
   //str�����a�U�F�@�ǫ��O��,�N�|�Q�s�i�r��
   //�ܼ�str�����ѧA�B�z

{
       object me;
       me=this_player();
       if(!str || str!="�C��") return 0;
       message_vision("�a�W���}�@�Ӭ},$N���`�N�K���U���C\n",me );
       me->move(__DIR__"den");
        
        tell_room(environment(this_player()),
        me->query("name")+"�q�W�Y�����U�ӡC\n", me);
        return 1;
}

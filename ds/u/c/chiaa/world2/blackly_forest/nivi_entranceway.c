//u/c/chiaa/world2/blackly_forest/nivi_entranceway.c

#include <ansi.h>     //�N���C�⪺��ƨөw�q�C��
inherit ROOM;
void create()
{
        set("short", "�Ԫ̧��J�f");
        set("long", @LONG
�o�̬O�·t�˪L���̲`�B,�|�P�����Ҧn�����H��z�L,
���O�b�o���H�ϵ}�֪��˪L,�|���H��b�o�̶�?!
�e�誺�۶��n�����I�_��!!
LONG
        );
        set("no_fight", 1);         //���T��@�԰ϰ�
        set("exits", ([ /* sizeof() == 1 */
          
         "west"       : __DIR__"vacancy2",     //�L���Ŧa2

]));
        
     set("item_desc",([
        "�۶�":"�@�ӥY�_���۶�,�i�H�յ۸I�I(touch)�ݡC\n",
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string str)  //�t�η|�N���a�ҿ�J��"touch"�o�ӫ��O�᪺�Ҧ�                             //��r�H�r�ꫬ�O���޼ƶǵ�do_touch()�@ 
                          //�N do_touch �o�Ө�ƫŧi��                                              //int do_touch(string str)
                          //str�����a�U�F�@�ǫ��O��,�N�|�Q�s�i�r��
                          //�ܼ�str�����ѧA�B�z�@
{
        object me;
       me=this_player();
        
          if(!str || str!="�۶�") return 0;
            message_vision("$N���U�������C\n",me );
      me->move(__DIR__"garrison2");
        
        tell_room(environment(this_player()),
        me->query("name")+"�q�W�������U�ӡC\n", me);
        return 1;
}


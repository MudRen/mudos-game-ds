//u/c/chiaa/world2/little flower_island/cliff2.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "�a�V");
        set("long",@LONG
�o�̬O�@�y�u�a�V�v���F���^���w�g�S�����󪺥X���F
���D�A���i�𪺸ܩ��U��,�i��|���_�J�]�����w,���L
�@�Ӥ��p�ߥi�O�|�L�ӯ����H��,�n�����e�n�n���Q�@�Q�a!!

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "north"   : __DIR__"rock4",    //���۰�4
  ]));
    set("item_desc",([
        "�a�V":"�ڥ��ݤ��쩳,���U��(jump)���ܬO�ܦM�I���Ҽ{�@�U�a�C\n",
     ]));

        set("no_clean_up", 0);
          setup();
}

void init()

{
        add_action("do_jump","jump");
}

int do_jump(string str)  //�t�η|�N���a�ҿ�J��"jump"�o�ӫ��O�᪺�Ҧ�                             //��r�H�r�ꫬ�O���޼ƶǵ� do_jump()�@ 
                          //�N do_jump �o�Ө�ƫŧi��                                              //int do_jump(string str)
                          //str�����a�U�F�@�ǫ��O��,�N�|�Q�s�i�r��
                          //�ܼ�str�����ѧA�B�z�@
{
        object me;
       me=this_player();
        
          if(!str || str!="�a�V") return 0;
            message_vision("$N���_�i��,���W����,���a���U�@��.�C\n",me );
      me->move(__DIR__"sand4");
        
        tell_room(environment(this_player()),
        me->query("name")+"�����q��B�����U�ӡC\n", me);
        return 1;
}

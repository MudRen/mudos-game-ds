//u/c/chiaa/world2/blackly_forest/assembly_room.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "�|ĳ��");
        set("long", @LONG
�o�O�Ԫ̧����|ĳ��,�̭����@�i�j��l�M�X�ӴȤl,
��W�@���p�����ۮѧl�ާA���`�N�O!
�b�o�̰Q�שM�M�w�����O�������̪����j�ƶ�,
�]����i�ӳo�̪��H,���O�����������Ԫ̴N�O���̪�����!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"nivi_square1",  //�s��1

        ]));
        
    set("item_desc",([
        "�ۮ�":"�@���_�Ǫ���,�ᦳ���q�C\n",
        ]));

        set("no_clean_up", 0);
        set("outdoors","ninja_village");
        setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string str)  //�t�η|�N���a�ҿ�J��"push"�o�ӫ��O�᪺�Ҧ�                             ��r�H�r�ꫬ�O���޼ƶǵ� do_push()�@ 
                         //�N do_push �o�Ө�ƫŧi��                                            //int do_push(string str)
                         //str�����a�U�F�@�ǫ��O��,�N�|�Q�s�i�r��
                         //�ܼ�str�����ѧA�B�z�@
{
        object me;
       me=this_player();
        
          if(!str || str!="�ۮ�") return 0;
            message_vision(
"$N�@�ѩ_�Ǫ��l�O,�N�A�l�F�i�h�C\n",me );
             me->move(__DIR__"den");
        
        tell_room(environment(this_player()),
        me->query("name")+"�Q�@�ѩ_�Ǫ��l�O�e��o�̡C\n", me);
        return 1;
}

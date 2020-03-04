// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", HIC"�s�ھF���]"NOR);
        set("long", @LONG
�A�b�@���Ȫ��̡A�o�O�������A�ȳ̦n�B�]�Ƴ̧������Ȫ��A�X�~��
�檺�H�@�w���|��J�b�o�̸ɥR�@��Ү��Ӫ���O�C�d�O�p�j�ˤ������e
���A�|�Pı�컫�ܦp�k���Pı�C
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"room068",
            "up"   : __DIR__"room104",
            ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/miss1.c" : 1,
                __DIR__"npc/h_boss.c" : 1,
        ]));

        set("no_clean_up", 0);
        set("valid_startroom",1);
        set("light", 1);
        set("no_fight",1);
        set("room_type","hotel");       // ���]

        set("item_desc", ([
                "note": (: look_sign :),
                "�i��": (: look_sign :),
        ]) );

        setup();
        call_other( "/obj/board/aovandis_b", "???" );
}
void init()
{
        add_action("do_dusting","dusting");
}

string look_sign(object me)
{
   if( file_size("/open/world2/shengsan/aovandis/note.txt") > 0 )
   {
    me->start_more( read_file("/open/world2/shengsan/aovandis/note.txt") );
    return "\n";
   } else return " SORRY. �����غc��. \n";
}
int room_effect(object me)
{
     int i;
     me=this_player();
     i=me->query_temp("addmoney");
    if(me->query_temp("dusting")>1 && query_temp("dustok") < 59 ) 
     {
       if(me->query("ap")<5) return notify_fail("�A����O�����F�A�L�k�A�����F�C\n");
       message_vision("$N�V�O�����r�㱽�r����a�O���G���������b�C\n",me);
       me->receive_damage("ap",5);
       me->set_temp("addmoney",i+1);
       set_temp("dustok",query_temp("dustok")+2);
     }
    if(me->query_temp("dusting") > 1 && query_temp("dustok") > 59)
    {
     tell_object(me,"�A�oı�a�O�����b�b�A�A�]������U���F�A�٬O���@�^�A�ӧa�C\n");
     call_out("delay",600,this_object());
            message_vision("���]�ѪO���D�G�����b�F�A���ΦA���F�I\n",me);
            message_vision("���]�ѪO�q�d�i���X�F"+ i*20 +"�T������$N�C\n",me);
            me->receive_money(i*20);
          me->delete_temp("addmoney");
          me->delete_temp("dusting");
    }
}

int valid_leave(object me, string dir)
{
if( dir=="west" && me->query_temp("dusting") >1 )
        {
          me->delete_temp("dusting");
          message_vision("$N�N���⩹�𨤤@��A����F�������u�@�C\n",me);
          return 0;
} else return ::valid_leave();
}

int do_dusting(string arg)
{
        object me;
        me=this_player();
        if(me->query_temp("dusting") == 0)
        {
          tell_object(me,"���]�ѪO�S���n�U�ΧA�A�A�N���������A�������A�n���դu�H\n");
         return 1;
        }
        else {
         if(me->query_temp("dusting")>1 ) return notify_fail("�A�w�g�{�u���b�����F�C\n");
          me->set_temp("dusting",2);
          message_vision("$N���_�F�𨤪�����A�}�l�{�u�������C\n",me);
            return 1;
        }
}
void delay(object room)
{
    object me;
    me=this_player();
   say("�a�O�V�ӶVż�F�A�A�oı���]�ѪO���y��ǩǪ��C\n");
        delete_temp("dustok");
     return;
}


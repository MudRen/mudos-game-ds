#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}�f"NOR);
 set("long",@LONG 
�o�̬O�j�}���}�f�A���̭��Q���w�R�A�s���w�ͳ��i�Hť��
�@�M�G���C���̭��ǨӰ}�}���˪��D���A���T���H�򰩮��M�A�p
�G�A�M�w�i�h�A�ȥ��n�Q���p�ߡA����ĵı�A���M�٬O���I���X
�}�f�a�I

LONG
    );

          set("item_desc",([
"���_" : NOR"�@�ӯU�������_�A���G�i�H���ݬ�(climb)�C\n"
           ]));
       set("exits",([
       "south":__DIR__"f1",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

void init()
{
add_action("do_climb","climb");
}

int do_climb(string arg)
{
string arg1;
object me;
me=this_player();
if (!arg) return notify_fail("�A�n������h�H\n");

if (arg!="���_") return notify_fail("�S���o�Ӧa��i�H���C\n");
if (arg=="���_") 
{
 message_vision(HIG"$N���W�誺���_���X�h�C\n"NOR,me);
 me->move("/u/c/coffee/area/north_area/town31");
 tell_object(me,"�A���X�F���_�A�oı�S�^��F���l�C\n");
}
                return 1;
}

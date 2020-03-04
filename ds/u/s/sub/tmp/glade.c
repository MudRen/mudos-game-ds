#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "�s���Ŧa");
        set("long", @LONG
�A���b�@�B�����W���s�����A�A�|�P����¶�۫d���J�����s���A���F
���p�i�Ӫ��s�_���~�A��b�A�䤣��X�f�C�s�����f���M�Z�A�j�b���W��
���K�H���N�A�����|���Ʈ�G��B����A���Ӥ]�ջD�����Q��C
LONG
        );

	set("item_desc",([
    "�s��":"�A�J�ӵ۬ݤF�ݤs���A���M�o�{�s�����Ӥ��ΦL���C\n",
	"���ΦL��":"���ΦL����`�J�s���Ƥo�A�����ѵM�Ӧ��A���G�O�د�Ұʪ������C\n",
	]) );
        set("exits", ([ /* sizeof() == 1 */
          "east" : __DIR__"rift1",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
	set("objects",([
	   __DIR__"npc/monkey":1,
	]) );
        setup();
}
void init()
{
	add_action("do_put","put");
}

int do_put(string arg)
{
	object me,claw;
	me=this_player();
 
      if(!arg || arg!="fist into ���ΦL��") return 0;
        if(!objectp(claw=present("sun-snow-fist",me) ) )
		return notify_fail("�A���W�èS���X�L�������ΪF��C\n");
	message_vision("$N���_�@�ӵo�۶�����~������J�s���������ΦL���C\n",me);
     message_vision(HIY "���M�@������÷�l�q�s��������F$N�A�H�Y�ֳt�u�ۮk���ӤW�I�I\n" NOR,me);
  me->delete_temp("jump-hole");
	me->move(__DIR__"temp-room");
	me->start_busy(2);
	call_out("show",3,me);
	return 1;	 
}

void show(object me)
{
	if(!me) return;
if (me->query_temp("jump-hole")==1) return 0;

	tell_object(me,"���ۤ@�n�A�A�����a�L�b�@�����a�C\n");
	me->move(__DIR__"ghat1");
     tell_room(environment(me),me->query("name")+"�~�۩��M�L�b�A���e�C\n",me);
	return;
}

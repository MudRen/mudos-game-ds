#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","�ĤG�X�Y");
	set("long",@LONG
�o�̬O�ĺ��Ĵ��ĤG�X�Y�A�]���ĺ��Ĵ���Ӫ���f�w�g�W�L�t���A
��ӴN�ѰӤH�X��سy�F�ĤG�X�Y�A�]�]���p���A�ĤG�X�Y���F�T���f��
�H�~�ä������L��A�i�H��O�ӤH���Ϊ��p����f�C�A�i�H�ݨ��|�P
�ﺡ�F�U���U�˪��f���C
LONG 
);
	set("exits",([
	    "east":__DIR__"port_18",
	    "west":__DIR__"port_16",
		]));
	set("objects",([
	    __DIR__"npc/waterman":3,
	    __DIR__"npc/business_wm":1,
		]));

	set("world","world1");
	set("outdoor","land");

	setup();

}
int valid_leave(object me, string dir)
{
	int temp = me->query_temp("police");
        if( (dir=="west") && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
	if( me->query_temp("police_area") == 2 && userp(me)) 
	{	
		temp++;
		me->set_temp("police",temp);
	}

        return ::valid_leave(me, dir);
}

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","�a�U���D");
	set("long",@LONG
�o�̴N�O�ĺ��Ĵ����a�U���D�t�ΤF�A�@�D�۱詹�W���ɨ��ĺ��Ĵ�
�s���A�Q��߬�i���۶���䦨���������c�A�|�P������h�J��F�U��
�U�ˤH�����A��b�o�̪��a���W�N���p��b�H�B�W�o�X�M�ܪ��T�n�A��
�Ӫ����y�b���D�����w�w���y�ʵۡA���o�̲רs�O�ӤU���D�A���M����
�c��H�Υ|�B�ö]���ѹ��C
LONG 
);	
	set("light",0);
	set("exits",([
	    "up":__DIR__"port_19",
	    "south":__DIR__"port_b2"
		]));
	set("world","world1");
	set("objects",([
	    __DIR__"npc/rat":3,
		]));

	setup();

}
int valid_leave(object me, string dir)
{
	int temp = me->query_temp("police");
	if(  me->query_temp("police_area")==1  && userp(me) && (dir != "up")) 
	{	
		temp++;
		me->set_temp("police",temp);
	}
        if( (dir=="up") && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}

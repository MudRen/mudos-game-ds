#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",GRN"�a�U�}��"NOR);
	set("long",@LONG
�@�ӥ��j���a�U�}�ެ�M�X�{�b���e�A�S�Q���ĺ��Ĵ����a�������o
���R������A�e�s���a�U�e�w�w���y�ʵۡA�b�e���U�I�I���å�������
�{�{�A�S�p�q�W������P�Ť@��C�b�F�n��y�����·t�������i�Hť��C
�I���q�n�A�j���b�|�P���Ů𤤡A�ٰʵۧA�F��`�B�C
LONG 
);	
	set("light",0);
	set("exits",([
	    "out":__DIR__"port_b4"
		]));
	set("world","world1");
	setup();

}
int valid_leave(object me, string dir)
{
 	mixed *m=me->query("sarsass_2");
 	m=([1,1,1]);
	if( (dir=="out") && me->query_temp("sarsass_test_q") > 0 && !this_player()->query("sarsass_2"))
 	{
 	 	if(!m)  me->set("sarsass_2",m);
		m[1]++;
 		//��������o�Ӧ欰�᪺�ݩʧ��ܡC//
 		me->set("sarsass_2",m);
	 }
        ::valid_leave(me, dir);
	}
	return ::valid_leave(me, dir);
}

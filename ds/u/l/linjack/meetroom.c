#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIB"�j�C�F"NOR);
 set("long",@LONG
�A�@�}�w�t, �N�Ө�F�o�Ӷǻ������j�C�F, �̭������F�ѤU�W�C,
�Y�O�b�v�����Ӫ��ɨ�, ���a�K�����{�{, �Y�q�C�B����, �K�|ı�o��
�B���o�ۤ@�D���t�L�񪺲H�����~, �ӤZ�H�S���i���k���ܦ�, ��M�|
�N���a�ǻ����@�B�P��. �Y�O����, �h���~�|�ƥh����, ���L���j�C
�F���H�Ϧ�ı�o�|�B���K�Ȥϥ�, ���o�H�H����.
LONG
    );
 set("exits",([
               "wiz":"/d/wiz/hall1",]));
 set("light",1);
 set("objects",([
		__DIR__"area/test/npc/shura":1,
 ]));
 set("valid_startroom", 1);
 setup();
 call_other("/u/l/linjack/linjack_b","???");
}
int valid_leave(object me, string dir)
{
 if( dir=="west" && !wizardp(me) )
  return notify_fail("���̥u���Ův�~��i�h�C\n");
 return ::valid_leave(me, dir);
}

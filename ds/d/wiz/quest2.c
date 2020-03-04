// Room: /u/l/luky/workroom.c
#include <ansi.h>  //�Y�n�Φ��C�⪺���[����
#include <room.h> //�n�[���n�o�@��
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short","�o���q�|");  //�u�ԭz
 set("long","\n"
	+"  �o�̬O�@�Ӽo���q�|���`�B, �|�g���O�@�ǩU��...�٦��@�Ǥp�Ĥl����\n"
	+"��(toy)�C�Ѧ��i�H�T�w�Y�ǫĤl�̯u����o�ӦM�I���a����F���K��a�F�C\n"
 ); //���ԭz
 set("exits", ([  //���ж��s�����X�f��V���ɮ�
 "south": __DIR__"quest1",
 ]));
 set("item_desc", ([
     "toy" : "�@�Ӯ]���Ū��ҫ������٦��@�Ǽu�]...�����äC�K�V����b�a�W�C\n",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 set("objects",([
 __DIR__"npc/boy":1,
 ]));
 create_door("south","�¦��K��","north",DOOR_LOCKED,"redkey");
 setup();
}

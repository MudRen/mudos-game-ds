#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ӥȹD�[����");
 set("long",@LONG
���M�W���Z�L�j�|, �]���ɥ~�Q���J�I�ɭP�Z�L�j�|�԰�,
���O�ӥȹD�[���M�d�F�ƦW�̤l�b�����ݶi�@�B������, �n�Y��
���^�q��. �A���e�Ҩ������O�ӥȯu�H���T�̤l--�u��D���u�d�u�v
�M��W�u��D�����̤l.
LONG
    );
 set("exits",([ "south":__DIR__"inroom17",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}

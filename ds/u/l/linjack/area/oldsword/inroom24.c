#include <room.h>
inherit ROOM;
void create()
{
 set("short","�W�N�x����");
 set("long",@LONG
�A�@�i��, �N�o�{�ƦW�x�L���n�ۧA��, ���Aı�o�������ۦb,
�J���@�F�@�|�P, �o�{�\�]�Q���@��, �ӥB�\�h�x�Ϋ~���b�̭�, 
�o�䯸�F�j���|���W���@��, ������������θ����j, ���W�t��]
����}, �s�ܻ�, �@�ݴN���D�O�t�v�Ҩ���Ĥ@���j�N ------
�u�q�F���Z�v, �O���W���Z����, �Q����j�|���F, �L�ٯd�b�V��
�󤧤�, �γ\�A���ӻ����n��p�ȥX�h�~�O.
LONG
    );
 set("exits",([ "north":__DIR__"inroom15",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}

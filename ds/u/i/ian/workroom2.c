#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIC"�쮦���u�@��"NOR);

 set("long",@LONG
�o�̴N�O�쮦���u�@��, �o�̧N�����o�F, �A���T�y����F�ָʶi
��, ���M�o�ɧA�i���ܦ��@���B�J�F, �o���ж������\�ۤ@�i�B�J���
�����줽��, �줽��e���ִȤw�g���B, �b�ж����t�@���٦��@�Ӥ���
, �W���}�ۤ@�������B�B, ��رi���O, �~�M���X�����Z�M�_����, �A
���T�h��, �o�Ӥu�@�Ǫ��D�H�O���O�믫�f�|�]�X�Ӫ�...
LONG
    );
 set("exits",([ "out":"/u/i/ian/workroom",
    ]));
        set("no_fight", 1);
        set("light",1);
 set("no_clean_up", 1);
 setup();
 replace_program(ROOM);
 

}


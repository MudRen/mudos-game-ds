#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���T�f");
set("long",@LONG
�A�Ө�T�f�����䤤�@���ж��A�o�̬ݨӧG�m��������O
�k�H���ж��A��W���ۤM�C�H���y�}���Z���A�ж��D�H�ӬO��
���n�Z�A�i�O�o�n���\�[�������H�ʹL�A�W�������@�ǻX�ФF
�A�i��~�X�\�[�C
LONG
    );
 set("exits",([
"west":__DIR__"yu_home",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             





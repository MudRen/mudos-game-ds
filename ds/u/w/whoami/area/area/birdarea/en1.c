#include <room.h> 
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");

 set("long",@LONG
�A�{�b�Ө�F�F�_�A�L���J�f�B, �F�_�A�L�o�Ӧa�誺���
�D�`����, �ݰ_�Ӥ����˪L, �ϦӤ�����h�A, �A�}�U���g�a��
�_���P�P�n�n��, �|�P�����\������, �ϱo�o�̦��ǳ��t, 
���F�_�q���F�_�A�L�C
LONG
    );
 
 set("exits",(["northeast":__DIR__"en2",
       ]));
 set("outdoors","forest");
 setup();
}           


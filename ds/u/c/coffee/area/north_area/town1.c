#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z����"NOR"��"HIG"�j��"NOR);
 set("long",@LONG 
�Ө�o�̡A���e�@��A���@�Ӥj�j���Φˤl�����j���A�̭�
���G�O�ӳ����C���o�س����o�Q���֨��A��a�Фl���γ�������
���N�Φˤl�f�ءA�s���q���o�u���ν_����л\�C
LONG
    );
 
 set("exits",(["north":__DIR__"town2",
           ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        


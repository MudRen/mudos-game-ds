#include "path.h"
inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�h�ΡA�L�����h�ΡA�ϧA�o�Ө��g�ʾԪ��W�žԱN�A�]���o���n
�n�𮧤@�f�F�A���̡̮A�k�̡̮A��Ӱ��b���a��A���ѧ��U�A���Y
����ѪšA�z�I�u�O�Ӭ��F�I�P�šB�������R���P�šI�q�o�̩񲴱�
�h�A�t�z�����U�جP�y�ɦ������A���p�����몺�Ȫe�B�{ģ�B�g�H��
�P�P�A�N�A�@���W�ұa�Ӫ����W�Τ��֡A�@���ӥh�A�A�u���I�ˤ��o
�_�����h�C
LONG
        );

        set("exits", ([
 "east" : HOLY+"h21",
 "westup" : HOLY+"h19",
        ]) );
        set("light",1);
        setup();
}

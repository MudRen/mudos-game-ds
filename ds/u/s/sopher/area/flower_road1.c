#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", HIC"���K���"NOR);
        set ("long", @LONG
                           ���� 
                            ��  ����   
                        ������������            
 �z�w�w�w�w�w�w�{       ������������   
 �x ���K���   �x         �� �� ��           �s   
 �x  �M�D���Y  �x            ��             /  \�s            
 �|�w�w�w�w�w�w�}    ^^^^^^^^��^^^^^^^^^^^^^^^^^^^^^^^^^
�A�@���i�o�����A�N�`�`�Q�L���ڭ��M�ŷx�Ұg�C
�v���a�ƪ������A��ں��ժ����P��A�p���i�H����
��....�o�@�����O���򪺬��n�A�A���q�ߩ��Ʊ�o�@
���û�����.........
LONG);   
        set("light",1);
        set("exits", ([
        "west": __DIR__"dragon5",
        "north": __DIR__"flower_room",
                  ]) );
       
        setup();
        replace_program(ROOM);
}


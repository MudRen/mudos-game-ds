#include <room.h>
inherit ROOM;
void create()
{
 set("short","�����}�]");
 set("long",@LONG
�n���e���ѨM�F����j��, �A�Ө�F�@�ӫշt���}�]����, �}�]��
���u���@���֥Υ����o�O, �A�ݨ�F�@���j�ۤ��W�٧��F�@�W���ۧA��
�Ѫ�, ��S�ۼC, �Y�a�ۤ�. ��誺�۾��W�i�H�M�����ݨ��٨�F����:

                ��   ��   �W   ��
                �n   �C   �b   ��
                �F   �D   ��   �l
                ��   ��   ��   ��
                �E   ��   �B   ��       ��
                �d   ��   ��   �L       �@
                ��   ��   ��   ��       ��
                                        
                                        �D
                                        
�g�o���֪��H�u�O�ۤj�ܷ�! �������O�o�ѳå�? �A�����_�������..
LONG
    );
 set("exits",([ "out":__DIR__"jungle18",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
// Room: /u/l/luky/room/pearl_1.c
#include <path.h>
inherit ROOM;
void create()
{
set("short", "[1;33m�ѹp����[m");
set("long", @LONG

[1;31m                  �d�d�d�d�d�d�d�d�d�d�d�d�d�d�d
                ����������������������������������
             ����������������[m[47;30m�w��Y�{[1;40;31m����������������
[0m�u�q�q�q�q�q�q�q�q[31m�m�n[1;33m�z�w�w�w�{�x�z�w�w�w�{[0;31m �m�n[m�q�q�q�q�q�q�q�q�t
�u�r�r�r�r�r�r�r�r[31m�m�n[1;33m�x      �x�x�x      �x[m[31m �m�n[m�r�r�r�r�r�r�r�r�t
[1m��[36m  .[32m"[37m   "    '[m[31m   �m�n[1;33m�x      ���x��      �x[m[31m �m�n[1;37m'�ȫȪ`�N!!     ��
��          . "[0;31m   �m�n[1;33m�x      �x�x�x      �x[0;31m �m�n[1;37m �Фų�W�~�X   ��
�� "    .[35m"[32m    `[31m   �m�n[33m�|�w�w�w�}�x�|�w�w�w�}[31m �m�n[37m,�H�K����!      ��
�r�w�w�w�w�w�w�w[31m�y���o[33m�w�w�w�w�w�r�w�w�w�w�w[31m|���o[37m�w�w�w�w�w�w�w�w�r[m

LONG
);

set("objects",([
__DIR__"npc/pearlguard":2,
]));
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pearl_2",
  "out" : __DIR__"pearl_0",
]));
set("no_clean_up", 0);
set("light", 1);
setup();
 load_object(__DIR__"pearl_8");
 load_object(__DIR__"pearl_10");
 load_object(__DIR__"pearl_12");
}

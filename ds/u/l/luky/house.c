// Room: /u/l/luky/room/house.c
#include <ansi.h>
inherit HOUSE;
void create()
{
   set_name(HIG"�s���O��"NOR, ({ "luky's house","house" }));
   set_short(HIG"�s���O��"NOR,HIG"�s���O�֫��U"NOR);
   set_long(@OUTLONG
�o�O�@���s�����O��, �n�i�h���ܴN enter house �a�C

OUTLONG
,@INLONG

               ((((((((((\
                ((_  _  )))))
                ))e) e ((((((|
               (((<     ))))))
                  \o    .-'-.
                /  `--.( _    '-.
  �Ѥ� ~ �֤F�� ~~    ::\  - _   '-.          _.-'''''-.
                      ::: ''-._-    '-.    .-'          `.
    �����A��~����~~  :::.  ': '-._    :-:'              :
                      ::::    : : ::.   :.               :
                      ::::     ' : ::.   ::..          .:
                      :: o     : : ::::.  :::)        .:
                      : ::`-.-'`'-'-'-'-;  )/        .:         .-._
                     :  .:              /  ;        .: _       /_   '-.__
                    :  .:              (''o\       .:'' '''-.-';; '-.    )
                      .:                \ |`      /.-''-._  _.;.-..-'```
                   ' .:                  \:      /        '`._/_   '-.__
            __.---' .:                   :                     ; '-._    )
           '====d..:/                     :___,;,,,,,,,,,,,,,,,;;....-'''`

INLONG
); // ���ԭz
/*
set("exits",([  //�X�f
"out":__DIR__"workroom",
]));
*/
set("light",1);
set("no_clean_up",1);
setup();

}

inherit ROOM;

void create()
{
        set("short", "���S���J-������");
        set("long", @LONG
�o��O���S���J�s���~���j��a�A���_�i�H�樣�֫ӭx
�P��H�K��ڲצ~���Ԫ��D�n�Ԧa�ж��S���J�s���A���M�o
��S���b�I�Ԥ��A���|�g��^�o�O�R�����ݵ±�����C�o��
���A���_�L�h�A���O�����F����AĲ�ةҤεL���O�R����
�Գ�����{����C
LONG
        );
        set("outdoors", "land");
        set("current_light", 5);
        set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"caodi10",
         "north" : "/open/world1/tmr/blood_field2/map_25_24",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


inherit ITEM;
void create()
{
        set_name("���I������", ({ "exri corpse", "corpse" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@long
�o�O�@����I(exri)���G�͡A�A�i�H�M���o�{����骺�U��������Q
�äM���ꪺ���ΡA�ӫ��骺�ݤf�g�ۡG�u�ڸѲ�F�v�|�Ӥj�r�A�A�@��ê��
�A�����½��L�ӡA���M�I�߼g�ۡG�u��½���F�v�|�Ӥj�r....
long
);
                set("unit", "��");
        }
        set("value",100);
        setup();
}


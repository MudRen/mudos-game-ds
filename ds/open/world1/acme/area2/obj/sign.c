inherit ITEM;
void create()
{
        set_name("��P", ({ "wood sign","sign" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"�o�@�����ª���P�A�W�Y��e�F���g�K���ϡC\n"
"               ________           \n"
"             ��  _��_  �@         \n"
"           ���@�� �� �@���@       \n"
"          ��__��_�z�{_��__��      \n"
"          ��  �� �|�} ��  ��      \n"
"           �@���@_��_���@��       \n"
"             �@___��___��         \n"
        );
        set("no_get",1);
        set("no_sac",1);
        }
     setup();
}

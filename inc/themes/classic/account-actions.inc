<?php use SP\Util\Checks; ?>

<div class="action">
    <?php if ($showDelete): ?>
        <button type="button" title="<?php echo _('Eliminar Cuenta'); ?>" class="button-action"
                OnClick="sysPassUtil.Common.delAccount(<?php echo $accountId; ?>,<?php echo \SP\Core\ActionsInterface::ACTION_ACC_DELETE; ?>,'<?php echo $sk; ?>');">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/delete.png" alt="save"/>
        </button>
    <?php endif; ?>

    <?php if ($showRestore): ?>
        <button type="submit" form="frmAccount" title="<?php echo _('Restaurar cuenta desde este punto'); ?>"
                class="button-action">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/restore.png" alt="save"/>
        </button>
    <?php endif; ?>

    <?php if ($showViewPass): ?>
        <button type="button" title="<?php echo _('Ver Clave'); ?>" class="button-action"
                onClick="sysPassUtil.Common.viewPass(<?php echo $accountId; ?>,1,<?php echo $accountIsHistory; ?>)">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/user-pass.png" alt="save"/>
        </button>

        <?php if (!Checks::accountPassToImageIsEnabled()): ?>
            <button type="button" title="<?php echo _('Copiar Clave en Portapapeles'); ?>"
                    class="button-action clip-pass-button"
                    data-account-id="<?php echo $accountId; ?>">
                <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/clipboard.png" alt="save"/>
            </button>
        <?php endif; ?>
    <?php endif; ?>

    <?php if ($showEditPass): ?>
        <button type="button" title="<?php echo _('Modificar Clave de Cuenta'); ?>" class="button-action"
                OnClick="sysPassUtil.Common.doAction(<?php echo \SP\Core\ActionsInterface::ACTION_ACC_EDIT_PASS; ?>, <?php echo $actionId; ?>,<?php echo $accountId; ?>)">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/key.png" alt="save"/>
        </button>
    <?php endif; ?>

    <?php if ($gotData && $accountIsHistory): ?>
        <button type="button" title="<?php echo _('Ver Actual'); ?>" class="button-action"
                OnClick="sysPassUtil.Common.doAction(<?php echo \SP\Core\ActionsInterface::ACTION_ACC_VIEW; ?>,<?php echo \SP\Core\ActionsInterface::ACTION_ACC_SEARCH; ?>,<?php echo $accountParentId; ?>)">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/back.png" alt="save"/>
        </button>
    <?php else: ?>
        <button type="button" title="<?php echo _('Volver'); ?>" class="button-action"
                OnClick="sysPassUtil.Common.doAction(<?php echo $lastAction; ?>, <?php echo $actionId; ?>,<?php echo $accountParentId; ?>)">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/back.png" alt="save"/>
        </button>
    <?php endif; ?>

    <?php if ($showEdit): ?>
        <button type="button" title="<?php echo _('Modificar Cuenta'); ?>" class="button-action"
                OnClick="sysPassUtil.Common.doAction(<?php echo \SP\Core\ActionsInterface::ACTION_ACC_EDIT; ?>,<?php echo \SP\Core\ActionsInterface::ACTION_ACC_VIEW; ?>,<?php echo $accountId; ?>)">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/edit.png" alt="save"/>
        </button>
    <?php elseif (!$showEdit && $actionId == \SP\Core\ActionsInterface::ACTION_ACC_VIEW && Checks::mailrequestIsEnabled()): ?>
        <button type="button" title="<?php echo _('Solicitar Modificación'); ?>" class="button-action"
                OnClick="sysPassUtil.Common.doAction(<?php echo \SP\Core\ActionsInterface::ACTION_ACC_REQUEST; ?>,<?php echo \SP\Core\ActionsInterface::ACTION_ACC_VIEW; ?>,<?php echo $accountId; ?>)">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/request.png" alt="save"/>
        </button>
    <?php endif; ?>

    <?php if ($showSave): ?>
        <button type="submit" form="frmAccount" title="<?php echo _('Guardar'); ?>" class="button-action">
            <img src="<?php \SP\Core\Init::$WEBURI; ?>imgs/check.png" alt="save"/>
        </button>
    <?php endif; ?>
</div>
package abi33_0_0.expo.modules.documentpicker;

import android.content.Context;

import java.util.Collections;
import java.util.List;

import abi33_0_0.org.unimodules.core.BasePackage;
import abi33_0_0.org.unimodules.core.ExportedModule;
import abi33_0_0.org.unimodules.core.ViewManager;

public class DocumentPickerPackage extends BasePackage {
  @Override
  public List<ExportedModule> createExportedModules(Context context) {
    return Collections.singletonList((ExportedModule) new DocumentPickerModule(context));
  }
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HPBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class FTPROJECT_API UHPBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	class UProgressBar* GetHPBar() { return HPBar; }

protected:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HPBar;
};

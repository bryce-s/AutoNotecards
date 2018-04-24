from django.http import HttpResponse
from django.shortcuts import render
from .models import PdfPack


def home(request):
    pack = PdfPack.objects.all()
    return render(request, 'home.html', {'PdfPacks': pack})

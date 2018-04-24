from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .models import PdfPack


def home(request):
    pack = PdfPack.objects.all()
    return render(request, 'home.html', {'PdfPacks': pack})

def new_pdf(request, pk):
    pack = get_object_or_404(PdfPack, pk=pk)
    return render(request, 'new_topic.html', {'PdfPack': pack})